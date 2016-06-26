#include <emacs-module.h>
#include <HsFFI.h>
#ifdef __GLASGOW_HASKELL__
#include "Lib_stub.h"
extern void __stginit_Lib(void);
#endif

/* Declare mandatory GPL symbol.  */
int plugin_is_GPL_compatible;

/* New emacs lisp function. All function exposed to Emacs must have this prototype. */
static emacs_value
Fmymod_test (emacs_env *env, ptrdiff_t nargs, emacs_value args[], void *data)
{

  /* bool (*copy_string_contents) (emacs_env *env, */
  /*                               emacs_value value, */
  /*                               char *buffer, */
  /*                               ptrdiff_t *size_inout); */

  /* /\* Create a Lisp string from a utf8 encoded string.  *\/ */
  /* emacs_value (*make_string) (emacs_env *env, */
  /*       		      const char *contents, ptrdiff_t length); */



  return env->make_integer (env, double_export(12));
}

/* Bind NAME to FUN.  */
static void
bind_function (emacs_env *env, const char *name, emacs_value Sfun)
{
  /* Set the function cell of the symbol named NAME to SFUN using
     the 'fset' function.  */

  /* Convert the strings to symbols by interning them */
  emacs_value Qfset = env->intern (env, "fset");
  emacs_value Qsym = env->intern (env, name);

  /* Prepare the arguments array */
  emacs_value args[] = { Qsym, Sfun };

  /* Make the call (2 == nb of arguments) */
  env->funcall (env, Qfset, 2, args);
}

/* Provide FEATURE to Emacs.  */
static void
provide (emacs_env *env, const char *feature)
{
  /* call 'provide' with FEATURE converted to a symbol */

  emacs_value Qfeat = env->intern (env, feature);
  emacs_value Qprovide = env->intern (env, "provide");
  emacs_value args[] = { Qfeat };

  env->funcall (env, Qprovide, 1, args);
}

int
emacs_module_init (struct emacs_runtime *ert)
{
  hs_init(NULL, NULL);
#ifdef __GLASGOW_HASKELL__
    hs_add_root(__stginit_Lib);
#endif

  emacs_env *env = ert->get_environment (ert);

  /* create a lambda (returns an emacs_value) */
  emacs_value fun = env->make_function (env,
              0,            /* min. number of arguments */
              0,            /* max. number of arguments */
              Fmymod_test,  /* actual function pointer */
              "doc",        /* docstring */
              NULL          /* user pointer of your choice (data param in Fmymod_test) */
  );

  bind_function (env, "mymod-test", fun);
  provide (env, "emacsplugin");

  /* loaded successfully */
  return 0;
}

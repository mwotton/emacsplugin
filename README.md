emacs 25 plugins for haskell
=========================

this is intended as a prototype (my ultimate goal is to hook up
http://github.com/mwotton/dustme up to elisp), but I'll leave this
here as a minimal example of how to call haskell from emacs.

Usage
=====

First, get emacs 25. This won't work with anything else.
Make a note of where it is, then edit stack.yaml:

```
extra-include-dirs:
  - ../../emacs/src
  ```

This will let ghc find the all-important emacs-module.h.
(There are some other important settings in stack.yaml, like the one to enable -fPIC
on a stack-wide basis.)

```
stack install --local-bin-path=SOMEDIRECTORY
```

This should install emacsplugin.so into the given directory.

I then run "emacs -Q -L SOMEDIRECTORY" (-Q because I don't want to run
my normal setup stuff, -L SOMEDIRECTORY to bring the module into
scope.)

We then evaluate

```
(require 'emacsplugin)
(mymod-test)
```

in a lisp buffer: mymod-test should return the result of multiplying
12 by 2 in Haskell. Not earthshattering, admittedly, but I'm currently
working on how to do marshalling.

Thanks
======

While I didn't end up using his code for marshalling, Niklas Hambüchen's
[call-haskell-from-anything](https://github.com/nh2/call-haskell-from-anything)
was extremely useful in working out how to build a .so file in
Haskell.

Thanks also to Aurélien Aptel for his explanation of the new [emacs
module system](http://diobla.info/blog-archive/modules-tut.html) and
how to call it from C.

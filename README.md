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

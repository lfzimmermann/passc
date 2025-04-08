# passc

# Building instructions (using nix)

* simply run ```nix-build``` in the projects root directory (where shell.nix is located) and it will build the project, and put the binary in 'result/bin/passc'.

# Run

* run ```nix-shell``` to enter an environment, where 'result/bin' was added to PATH.
* to run simply type ```passc```

* else just run ```result/bin/passc``` to skip the nix-shell.


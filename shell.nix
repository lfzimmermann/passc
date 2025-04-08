let
  nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-24.11";
  pkgs = import nixpkgs { config = {}; overlays = []; };
in
pkgs.mkShell {
  shellHook = ''
		PROJDIR=$(pwd)
		PATH=$PROJDIR/result/bin/:$PATH
  '';
}

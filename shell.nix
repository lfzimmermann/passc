let
  nixpkgs = fetchTarball "https://github.com/NixOS/nixpkgs/tarball/nixos-24.11";
  pkgs = import nixpkgs { config = {}; overlays = []; };
in
pkgs.mkShell {
  packages = with pkgs; [
		ncurses
		pkg-config
		prettierd
		clang
		gcc
		libclang
		libcxx
		ninja
		meson
  ];
  shellHook = ''
		nix-build
		PROJDIR=$(pwd)
		PATH=$PROJDIR/result/bin/:$PATH
		passc &&
		exit
  '';
}

{ pkgs ? import <nixpkgs> {} }:
with pkgs;
		stdenv.mkDerivation {
				name = "passc-1.0";
				src = ./.;


				nativeBuildInputs = [
						meson
						ninja
						pkg-config
				];

				buildInputs = [
						ncurses
				];

				configurePhase = ''
						meson setup --wipe build
				'';

				buildPhase = ''
						ninja -C build
				'';

				installPhase = ''
						echo "Files are at: $out"
						mkdir -p $out/bin
						cp build/hello $out/bin/passc
				'';
				
		}

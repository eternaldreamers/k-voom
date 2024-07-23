{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.ccls
    pkgs.scons
    pkgs.godot_4
    pkgs.python3
    pkgs.python311Packages.jedi
  ];
 
  shellHook = ''
    alias godot="godot4"

    echo "nix-shell initialized! :))"
  '';
}

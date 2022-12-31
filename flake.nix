{
  description = "Zephyr C++ API - Development Environment";

  inputs = {
    nixpkgs.url = "nixpkgs/22.11";
    flake-utils.url = "github:numtide/flake-utils";

    zephyr-arm-dev = {
      url = "github:almini/nix-zephyr-arm-dev";
      inputs.nixpkgs.follows = "nixpkgs";
      inputs.flake-utils.follows = "flake-utils";
    };
  };

  outputs = { ... }@inputs: inputs.flake-utils.lib.eachSystem [ "x86_64-linux" "aarch64-linux" ] (system:
    let
      pkgs = import inputs.nixpkgs { inherit system; };
    in
    {
      devShells.default = inputs.zephyr-arm-dev.devShells.${system}.default.overrideAttrs (final: prev: {
        buildInputs = prev.buildInputs ++ [
          pkgs.addlicense
          pkgs.clang
        ];
      });
    });
}

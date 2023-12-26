import os
from conan import ConanFile
from conan.tools.files import copy


class GrilledRadishRecipe(ConanFile):
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'PremakeDeps'

    def requirements(self):
        self.requires('glfw/3.3.8')
        self.requires('spdlog/1.12.0')
        self.requires('glad/0.1.36')
        self.requires('glm/cci.20230113')
        self.requires('imgui/cci.20230105+1.89.2.docking')

    def generate(self):
        copy(self, "*glfw*", os.path.join(self.dependencies["imgui"].package_folder,
            "res", "bindings"), os.path.join(self.source_folder, "bindings/imgui"))
        copy(self, "*opengl3*", os.path.join(self.dependencies["imgui"].package_folder,
            "res", "bindings"), os.path.join(self.source_folder, "bindings/imgui"))

    def configure(self):
        self.options['glad'].gl_profile = 'core'
        self.options['glad'].gl_version = '4.5'
import os
import shutil
from conan import ConanFile
from conan.tools.files import copy


class RadishRecipe(ConanFile):
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'PremakeDeps'

    def requirements(self):
        self.requires('entt/3.13.0')
        self.requires('glm/cci.20230113')
        self.requires('glfw/3.3.8')
        self.requires('glad/0.1.36')
        self.requires('spdlog/1.13.0')
        self.requires('imgui/cci.20230105+1.89.2.docking')

    def configure(self):
        self.options['glad'].gl_profile = 'core'
        self.options['glad'].gl_version = '4.5'

    def generate(self):
        self.generate_imgui()

    def generate_imgui(self):
        bindings_folder_src = self.dependencies['imgui'].cpp_info.srcdirs[0]
        bindings_folder_dst = os.path.join(self.build_path, 'imgui-bindings')

        shutil.copytree(src=bindings_folder_src, dst=bindings_folder_dst, dirs_exist_ok=True)
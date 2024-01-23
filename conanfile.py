from conan import ConanFile


class TemplateRecipe(ConanFile):
    settings = 'os', 'compiler', 'build_type', 'arch'
    generators = 'PremakeDeps'

    def requirements(self):
        pass

    def configure(self):
        pass

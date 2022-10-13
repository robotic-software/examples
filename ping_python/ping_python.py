from isaac import *


class PingPython(Codelet):
    def start(self):
        self.tick_periodically(1.0)

    def tick(self):
        print(self.config.message)


def main():
    app = Application(app_filename="apps/examples/ping_python/ping_python.app.json")
    app.nodes["ping_node"].add(PingPython)
    app.run()


if __name__ == '__main__':
    main()

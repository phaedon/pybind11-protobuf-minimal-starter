import unittest

import helloworld_pybind


class TestHelloWorld(unittest.TestCase):
    def test_helloworld(self):
        result = helloworld_pybind.create()
        self.assertEqual("Hello world", result.id)
        self.assertEqual(3, result.duration.seconds)

if __name__ == "__main__":
    unittest.main()

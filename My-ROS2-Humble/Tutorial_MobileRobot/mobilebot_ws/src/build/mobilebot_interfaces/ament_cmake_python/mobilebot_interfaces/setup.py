from setuptools import find_packages
from setuptools import setup

setup(
    name='mobilebot_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('mobilebot_interfaces', 'mobilebot_interfaces.*')),
)

from setuptools import find_packages
from setuptools import setup

setup(
    name='talk_to_mcu_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('talk_to_mcu_interfaces', 'talk_to_mcu_interfaces.*')),
)

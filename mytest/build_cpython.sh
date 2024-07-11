git clone https://github.com/python/cpython
cd cpython
git checkout -b 3.10 origin/3.10
mkdir build
cd build
export PYTHON_MAJOR=3
export PYTHON_VERSION=3.10
../configure --prefix=/opt/python/${PYTHON_VERSION} --with-pydebug
make -j$(nproc)
sudo make install
curl -O https://bootstrap.pypa.io/get-pip.py
sudo /opt/python/${PYTHON_VERSION}/bin/python${PYTHON_MAJOR} get-pip.py
/opt/python/3.10/bin/python3 -m pip install --upgrade pip
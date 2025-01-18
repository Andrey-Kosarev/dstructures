set -e

rm -rf dist *.egg-info


python3 -m build
pip install dist/dstructures-0.0.1-cp313-cp313-linux_x86_64.whl --force-reinstall

rm -rf dist *.egg-info

echo 
echo "TESTING..."
pytest -q
import pytest
from dstructures.tree import BinarySearchTree
import random

@pytest.fixture
def random_values():
    return [random.randint(-100, 100) for _ in range(50)]


def test_simple_insert():
    bst = BinarySearchTree(0)
    bst.insert(5)
    assert bst.left is None
    assert bst.right is not None
    assert bst.right.value == 5

    bst.insert(-5)
    assert bst.left is not None
    assert bst.right is not None
    assert bst.left.value == -5

def test_simple_search():
    bst = BinarySearchTree(0)
    bst.insert(5)
    assert bst.search(5)
    assert bst.search(0)
    assert not bst.search(15)


def test_search(random_values):
    bst = BinarySearchTree(0)

    for v in random_values:
        bst.insert(v)
    
    for v in random_values:
        assert bst.search(v)


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def unique_bsts_preorder(n):
    if n == 0:
        return []

    def generate_trees(start, end):
        if start > end:
            return [None]

        result = []
        for i in range(start, end + 1):
            left_trees = generate_trees(start, i - 1)
            right_trees = generate_trees(i + 1, end)

            for left in left_trees:
                for right in right_trees:
                    root = TreeNode(i)
                    root.left = left
                    root.right = right
                    result.append(root)

        return result

    def pre_order_traversal(node, result):
        if node:
            result.append(node.val)
            pre_order_traversal(node.left, result)
            pre_order_traversal(node.right, result)

    trees = generate_trees(1, n)
    unique_results = []

    for tree in trees:
        result = []
        pre_order_traversal(tree, result)
        unique_results.append(result)

    return unique_results

n = 8
result = unique_bsts_preorder(n)
print(result)
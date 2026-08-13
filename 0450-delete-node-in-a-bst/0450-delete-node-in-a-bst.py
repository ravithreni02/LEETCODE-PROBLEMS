class Solution:
    def deleteNode(self, root, key):
        # Base Case: The tree or subtree is empty
        if not root:
            return None
        
        # Step 1: Navigate to the target node
        if key < root.val:
            root.left = self.deleteNode(root.left, key)
        elif key > root.val:
            root.right = self.deleteNode(root.right, key)
        else:
            # Step 2: Target node found. Handle the deletion cases.
            if not root.left:
                return root.right
            if not root.right:
                return root.left
            
            # Case 3: Two children
            successor = root.right
            while successor.left:
                successor = successor.left
            
            root.val = successor.val
            root.right = self.deleteNode(root.right, successor.val)
            
        return root


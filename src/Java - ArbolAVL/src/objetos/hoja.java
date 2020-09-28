package objetos;

public class hoja {
	// Atributos 
	private int root;
	private hoja left;
	private hoja right;
	
	// Constructor
	public hoja(int root, hoja left, hoja right) {
		this.root = root;
		this.left = left;
		this.right = right;
	}

	// Set and Get
	public int getRoot() {
		return root;
	}

	public void setRoot(int root) {
		this.root = root;
	}

	public hoja getLeft() {
		return left;
	}

	public void setLeft(hoja left) {
		this.left = left;
	}

	public hoja getRight() {
		return right;
	}

	public void setRight(hoja right) {
		this.right = right;
	}
	
}

package execoes;

public class EstoqueVazioException extends Exception {
    public EstoqueVazioException() {
    }

    public EstoqueVazioException(String message) {
        super(message);
    }
}

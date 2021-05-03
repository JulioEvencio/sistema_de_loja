package excecoes;

public class QuantidadeInvalidaException extends Exception {
    public QuantidadeInvalidaException() {
    }

    public QuantidadeInvalidaException(String message) {
        super(message);
    }
}

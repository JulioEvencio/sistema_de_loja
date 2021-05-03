package excecoes;

public class CodigoInvalidoException extends Exception {
    public CodigoInvalidoException() {
    }

    public CodigoInvalidoException(String message) {
        super(message);
    }
}

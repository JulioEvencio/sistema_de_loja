package excecoes;

public class LoginInvalidoException extends Exception {
    public LoginInvalidoException() {
    }

    public LoginInvalidoException(String message) {
        super(message);
    }
}

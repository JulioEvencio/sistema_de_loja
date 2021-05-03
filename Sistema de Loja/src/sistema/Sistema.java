package sistema;

import usuarios.Usuario;
import excecoes.LoginInvalidoException;
import java.util.HashMap;

public class Sistema {
    private static Usuario usuario;
    private static HashMap<String, Usuario> cadastro = new HashMap<>();

    public static String getUsuarioNome() {
        return usuario.getNome();
    }

    public static void cadastrarUsuario(String nome, String login, String senha) throws LoginInvalidoException {
        if (cadastro.containsKey(login)) throw new LoginInvalidoException();

        usuario = new Usuario(nome, login, senha);
        cadastro.put(login, usuario);
    }

    public static boolean validarLogin(String login, String senha) {
        if (!cadastro.containsKey(login)) return false;

        usuario = cadastro.get(login);

        if (usuario.validarLogin(login, senha)) return true;

        usuario = null;

        return false;
    }

    public static void resetarUsuario() {
        usuario = null;
    }
}

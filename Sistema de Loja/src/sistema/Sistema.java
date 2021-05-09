package sistema;

import loja.Loja;
import usuarios.Usuario;
import excecoes.LoginInvalidoException;
import excecoes.CodigoInvalidoException;
import java.util.HashMap;

public class Sistema {
    private static Usuario usuario;
    private static Loja loja;
    private static HashMap<String, Usuario> cadastro = new HashMap<>();

    public static String getUsuarioNome() {
        return usuario.getNome();
    }

    public static int[] getCodigoLojas() {
        return usuario.getCodigoLoja();
    }

    public static String getRelatorio() {
        return loja.getRelatorio();
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

    public static void criarLoja(int codigo, String nome, double capital) throws CodigoInvalidoException {
        usuario.criarLoja(codigo, nome, capital);
    }

    public static void deletarLoja(int codigo) throws CodigoInvalidoException {
        usuario.deletarLoja(codigo);
    }

    public static void abrirLoja(int codigo) throws CodigoInvalidoException {
        loja = usuario.getLoja(codigo);
    }
}
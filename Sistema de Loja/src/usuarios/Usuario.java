package usuarios;

import loja.Loja;
import excecoes.CodigoInvalidoException;
import java.util.HashMap;

public final class Usuario {
    private final String nome;
    private final String login;
    private final String senha;
    private final HashMap<Integer, Loja> lojas;

    public Usuario(String nome, String login, String senha) {
        this.nome = nome;
        this.login = login;
        this.senha = senha;
        this.lojas = new HashMap<>();
    }

    public String getNome() {
        return nome;
    }

    public String getLogin() {
        return login;
    }

    public String getSenha() {
        return senha;
    }

    public Loja getLoja(int codigo) throws CodigoInvalidoException {
        if (!lojas.containsKey(codigo)) throw new CodigoInvalidoException();

        return lojas.get(codigo);
    }

    public boolean validarLogin(String login, String senha) {
        if (this.login.equals(login) && this.senha.equals(senha)) return true;
        else return false;
    }

    public void criarLoja(int codigo, String nome, double capital) throws CodigoInvalidoException {
        if (lojas.containsKey(codigo)) throw new CodigoInvalidoException();
        else lojas.put(codigo, new Loja(codigo, nome, capital));
    }

    public void deletarLoja(int codigo) throws CodigoInvalidoException {
        if (!lojas.containsKey(codigo)) throw new CodigoInvalidoException();
        else lojas.remove(codigo);
    }
}

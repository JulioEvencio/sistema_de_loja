package loja;

import produto.Produto;
import excecoes.CodigoInvalidoException;
import excecoes.EstoqueVazioException;
import excecoes.QuantidadeInvalidaException;
import java.util.HashMap;

public class Loja {
    private String nome;
    private double capital;
    private final HashMap<Integer, Produto> estoque;

    public Loja(String nome, double capital) {
        this.nome = nome;
        this.capital = capital;
        this.estoque = new HashMap<>();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getCapital() {
        return capital;
    }

    public void setCapital(double capital) {
        this.capital = capital;
    }

    public void cadastrarProduto(int codigo, String nome, double preco) throws CodigoInvalidoException {
        Produto produto = new Produto(codigo, nome, preco);

        if (estoque.containsKey(codigo)) throw new CodigoInvalidoException();

        estoque.put(codigo, produto);
    }

    public Produto localizarProduto(int codigo) throws EstoqueVazioException, CodigoInvalidoException {
        if (estoque.isEmpty()) throw new EstoqueVazioException();
        if (!estoque.containsKey(codigo)) throw new CodigoInvalidoException();

        return estoque.get(codigo);
    }

    public void removerProduto(int codigo) throws EstoqueVazioException, CodigoInvalidoException {
        if (estoque.isEmpty()) throw new EstoqueVazioException();
        if (!estoque.containsKey(codigo)) throw new CodigoInvalidoException();

        estoque.remove(codigo);
    }

    public double venderProduto(int codigo, int quantidade) throws EstoqueVazioException, CodigoInvalidoException, QuantidadeInvalidaException {
        Produto produto;

        if (estoque.isEmpty()) throw new EstoqueVazioException();
        if (!estoque.containsKey(codigo)) throw new CodigoInvalidoException();
        if (quantidade < 1) throw new QuantidadeInvalidaException();

        produto = estoque.get(codigo);

        if (produto.getQuantidade() < quantidade) throw new QuantidadeInvalidaException();

        produto.setQuantidade(produto.getQuantidade() - quantidade);

        capital += produto.getPreco() * quantidade;

        estoque.put(codigo, produto);

        return produto.getPreco() * quantidade;
    }

    public void reporProduto(int codigo, int quantidade) throws EstoqueVazioException, CodigoInvalidoException, QuantidadeInvalidaException {
        Produto produto;

        if (estoque.isEmpty()) throw new EstoqueVazioException();
        if (!estoque.containsKey(codigo)) throw new CodigoInvalidoException();
        if (quantidade < 1) throw new QuantidadeInvalidaException();

        produto = estoque.get(codigo);
        produto.setQuantidade(produto.getQuantidade() + quantidade);
        estoque.put(codigo, produto);
    }
}

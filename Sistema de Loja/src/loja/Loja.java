package loja;

import produto.Produto;
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

    public void cadastrarProduto(int codigo, String nome, double preco) {
        Produto produto = new Produto(codigo, nome, preco);

        if (estoque.containsKey(codigo)) throw new RuntimeException();

        estoque.put(codigo, produto);
    }

    public Produto localizarProduto(int codigo) {
        if (estoque.isEmpty()) throw new RuntimeException();
        if (!estoque.containsKey(codigo)) throw new RuntimeException();

        return estoque.get(codigo);
    }

    public void removerProduto(int codigo) {
        if (estoque.isEmpty()) throw new RuntimeException();
        if (!estoque.containsKey(codigo)) throw new RuntimeException();

        estoque.remove(codigo);
    }

    public double venderProduto(int codigo, int quantidade) {
        Produto produto;

        if (estoque.isEmpty()) throw new RuntimeException();
        if (!estoque.containsKey(codigo)) throw new RuntimeException();
        if (quantidade < 1) throw new RuntimeException();

        produto = estoque.get(codigo);

        if (produto.getQuantidade() < quantidade) throw new RuntimeException();

        produto.setQuantidade(produto.getQuantidade() - quantidade);

        capital += produto.getPreco() * quantidade;

        estoque.put(codigo, produto);

        return produto.getPreco() * quantidade;
    }

    public void reporProduto(int codigo, int quantidade) {
        Produto produto;

        if (estoque.isEmpty()) throw new RuntimeException();
        if (!estoque.containsKey(codigo)) throw new RuntimeException();
        if (quantidade < 1) throw new RuntimeException();

        produto = estoque.get(codigo);
        produto.setQuantidade(produto.getQuantidade() + quantidade);
        estoque.put(codigo, produto);
    }
}

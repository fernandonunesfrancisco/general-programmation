
import java.io.*;
import java.util.*;

/**
 * 
 */
public class Pokemon {

    /**
     * Default constructor
     */
    public Pokemon() {
    }

    /**
     * 
     */
    private String nome;

    /**
     * 
     */
    private int nivel;

    /**
     * 
     */
    private Natureza natureza;

    /**
     * 
     */
    private TIpo tipo1;

    /**
     * 
     */
    private Tipo tipo2;

    /**
     * 
     */
    private Estatisticas baseStats;

    /**
     * 
     */
    private Estatisticas ivs;

    /**
     * 
     */
    private Estatisticas evs;

    /**
     * 
     */
    private Estatisticas statsCombate;

    /**
     * 
     */
    private List<Movimento> movimentos;

    /**
     * 
     */
    private int hpAtual;






    /**
     * @param builder
     */
    private Pokemon(PokemonBuilder builder) {
        // TODO implement here
    }

    /**
     * @return
     */
    private void calcularStatsDeCombate() {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    private int calcularHpMaximo() {
        // TODO implement here
        return 0;
    }

    /**
     * @param atributo 
     * @return
     */
    private int calcularEstatistica(Atributo atributo) {
        // TODO implement here
        return 0;
    }

    /**
     * @param dano 
     * @return
     */
    public void receberDano(int dano) {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    public void curarTotalmente() {
        // TODO implement here
        return null;
    }

    /**
     * @param t 
     * @return
     */
    public boolean temTipo(Tipo t) {
        // TODO implement here
        return false;
    }

    /**
     * @return
     */
    public boolean isDesmaiado() {
        // TODO implement here
        return false;
    }

    /**
     * @return
     */
    public String getNome() {
        // TODO implement here
        return "";
    }

    /**
     * @return
     */
    public Estatisticas getEstatisticas() {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    public List<Movimento> getMovimentos() {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    public int getHpAtual() {
        // TODO implement here
        return 0;
    }

    /**
     * @return
     */
    public Tipo getTipo1() {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    public Tipo getTipo2() {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    public Natureza getNatureza() {
        // TODO implement here
        return null;
    }

}
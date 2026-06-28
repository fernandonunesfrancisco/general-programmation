
import java.io.*;
import java.util.*;

/**
 * 
 */
public class PokemonBuilder {

    /**
     * Default constructor
     */
    public PokemonBuilder() {
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
    private Tipo tipo1;

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
    private List<Movimento> movimentos;

    /**
     * 
     */
    public PokemonBuilder() {
        // TODO implement here
    }

    /**
     * @param nome 
     * @param t1 
     * @param t2 
     * @return
     */
    public PokemonBuilder setDadosBase(String nome, Tipo t1, Tipo t2) {
        // TODO implement here
        return null;
    }

    /**
     * @param base 
     * @return
     */
    public PokemonBuilder setEstatisticasPadrao(Estatisticas base) {
        // TODO implement here
        return null;
    }

    /**
     * @param natureza 
     * @return
     */
    public PokemonBuilder setNatureza(Natureza natureza) {
        // TODO implement here
        return null;
    }

    /**
     * @param m 
     * @return
     */
    public PokemonBuilder adicionarMovimento(Movimento m) {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    public Pokemon build() {
        // TODO implement here
        return null;
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
    public int getNivel() {
        // TODO implement here
        return 0;
    }

    /**
     * @return
     */
    public Natureza getNatureza() {
        // TODO implement here
        return null;
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
    public Estatisticas getBaseStats() {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    public Estatisticas getIvs() {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    public Estatisticas getEvs() {
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

}

import java.io.*;
import java.util.*;

/**
 * 
 */
public class Treinador {

    /**
     * Default constructor
     */
    public Treinador() {
    }

    /**
     * 
     */
    private String nome;

    /**
     * 
     */
    private List<Pokemon> equipe;

    /**
     * 
     */
    private EstrategiaDecisao estrategia;




    /**
     * @param nome 
     * @param estrategia
     */
    public Treinador(String nome, EstrategiaDecisao estrategia) {
        // TODO implement here
    }

    /**
     * @param p 
     * @return
     */
    public void adicionarPokemon(Pokemon p) {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    public Pokemon getPokemonAtivo() {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    public boolean temPokemonApto() {
        // TODO implement here
        return false;
    }

    /**
     * @param p 
     * @return
     */
    public void colocarComoAtivo(Pokemon p) {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    public void curarEquipe() {
        // TODO implement here
        return null;
    }

    /**
     * @param inimigo 
     * @return
     */
    public ComandoTurno solicitarAcao(Treinador inimigo) {
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
    public List<Pokemon> getEquipe() {
        // TODO implement here
        return null;
    }

    /**
     * @return
     */
    public EstrategiaDecisao getEstrategia() {
        // TODO implement here
        return null;
    }

}
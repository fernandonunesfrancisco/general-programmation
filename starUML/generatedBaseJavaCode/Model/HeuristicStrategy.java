
import java.io.*;
import java.util.*;

/**
 * 
 */
public class HeuristicStrategy {

    /**
     * Default constructor
     */
    public HeuristicStrategy() {
    }

    /**
     * 
     */
    private boolean ultimoTurnoFoiTroca;

    /**
     * @param aliado 
     * @param inimigo 
     * @return
     */
    public ComandoTurno escolherAcao(Treinador aliado, Treinador inimigo) {
        // TODO implement here
        return null;
    }

    /**
     * @param aliado 
     * @param inimigo 
     * @return
     */
    public Pokemon escolherSubstituto(Treinador aliado, Pokemon inimigo) {
        // TODO implement here
        return null;
    }

    /**
     * @param aliado 
     * @param inimigo 
     * @return
     */
    private boolean deveTrocar(Treinador aliado, Pokemon inimigo) {
        // TODO implement here
        return false;
    }

    /**
     * @param atacante 
     * @param defensor 
     * @return
     */
    private double calcularRiscoTipagem(Pokemon atacante, Pokemon defensor) {
        // TODO implement here
        return 0.0d;
    }

    /**
     * @param atacante 
     * @param defensor 
     * @return
     */
    private Movimento obterMelhorMovimento(Pokemon atacante, Pokemon defensor) {
        // TODO implement here
        return null;
    }

}
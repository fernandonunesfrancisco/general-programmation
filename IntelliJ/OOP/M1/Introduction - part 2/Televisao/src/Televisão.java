public class Televisão {
    private int volume;
    private int canal;
    private boolean estado;

    public Televisão(int volume, int canal, boolean estado) {
        if(canal>=1 && canal <=16) this.canal=canal;
        if(volume>=0 && volume<=10) this.volume=volume;
        this.estado=estado;
    }
    public void aumentarVolume(){
        if(estahLigado()){
            if(volume<10) volume++;
            else System.out.println("Volume no maximo.");
        }
        else System.out.println("Televisao desligada.");
    }

    public void reduzirVolume(){
        if(estahLigado()){
            if(volume>0) volume--;
            else System.out.println("Volume no minimo.");
        }
        else System.out.println("Televisao desligada.");
    }

    public void subirCanal(){
        if(estahLigado()){
            if(canal<10) canal++;
            else System.out.println("Canal atual: canal 10 (maximo).");
        }
        else System.out.println("Televisao delisgada.");
    }

    public void descerCanal(){
        if(estahLigado()){
            if (canal>0) canal--;
            else System.out.println("Canal atual: canal 1 (minimo).");
        }
        else System.out.println("Televisao desligada.");
    }

    public void ligar(){
        if(estahLigado()==false){
            estado=true;
        }
        else System.out.println("TV ja esta ligada.");
    }

    public void desligar(){
        if(estahLigado()){
            estado=false;
        }
        else System.out.println("TV ja esta desligada.");
    }

    public boolean estahLigado(){
        return estado;
    }
    @Override
    public String toString(){
        if(estahLigado()) return String.format("Televisao ligada - canal= %d, volume =%d%n", getCanal(), getVolume());
        else return("Televisao esta desligada.");
    }

    public int getVolume() {
        return volume;
    }

    public int getCanal() {
        return canal;
    }
}

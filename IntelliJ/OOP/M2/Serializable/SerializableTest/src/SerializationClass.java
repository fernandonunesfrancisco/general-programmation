import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class SerializationClass {
    public static void recordBinFile(ArrayList<Object> list, String nameFile) {
        File arq= new File(nameFile);
        try{
            arq.delete();
            arq.createNewFile();
            ObjectOutputStream objOutput = new ObjectOutputStream(new FileOutputStream(arq));
            objOutput.writeObject(list);
            objOutput.close();
        }
        catch(IOException error){
            System.out.printf("Error: $s", error.getMessage());
        }
    }
    public static ArrayList<Object> readBinFile(ArrayList<Object> list, String nameFile) {
        File arq= new File(nameFile);
        try{
            File arq = new File(nameFile);
            if(arq.exists()){
                ObjectInputStream objInput =new ObjectInputStream(new FileInputStream(arq));
                lista = (ArrayList<Object>) objInput.readObject();
                objInput.close();
            }
        }catch(IOException error1){
            System.out.printf("Error: $s", error1.getMessage());
        }catch(ClassNotFoundException error2){
            System.out.printf("Error: $s", error2.getMessage());
        }
        return(lista);
    }
}

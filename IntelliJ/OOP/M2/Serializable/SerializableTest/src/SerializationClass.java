import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;


public class SerializationClass {
    public static void recordBinFile(ArrayList<Object> list, String nameFile) {
        File arq= new File(nameFile);
        try{
            arq.delete();
            arq.createNewFile;
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
            File arq = new File(nameFile)
        }
    }
}

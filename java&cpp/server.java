import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class server
{
    public static void main(String[] args) throws Exception {
        //declarar variables de socket y hacer la conexion
        ServerSocket serverSocket = null; 
        Socket clientSocket = null;
        serverSocket = new ServerSocket(8000); //8000 es el numero de puerto
        System.out.println("Esperando conexion");
        clientSocket = serverSocket.accept(); //se pone en pausa a escuchar hasta que se haga una conexion

        //escribir en el socket
        BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream())); 
        wr.write("My Messages!");
        wr.flush(); //le hace flush al stream

        //leer del socket
        String inputLine; 
        BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); 
        while((inputLine = in.readLine()) != null){
            System.out.println(inputLine);
        }

        //cerrar la conexion
        serverSocket.close();
        clientSocket.close();
    }
}
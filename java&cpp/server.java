import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class server{
    //declarar variables de socket y hacer la conexion
    private static ServerSocket serverSocket = null;
    private static Socket clientSocket = null;

    public server()throws Exception{
        serverSocket = new ServerSocket(6000); //8000 es el numero de puerto
        System.out.println("Esperando conexion");
        clientSocket = serverSocket.accept(); //se pone en pausa a escuchar hasta que se haga una conexion
    }

    public static void write(String mensaje)throws Exception{
        //escribir en el socket
        BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream())); 
        wr.write(mensaje);
        wr.flush(); //le hace flush al stream
        

    }

    public static void read() throws Exception {

        //leer del socket
        String inputLine; 
        BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); 
        while((inputLine = in.readLine()) != null){
            System.out.println(inputLine);
        }
    }

    public static void closeSockets()throws Exception{
        //cerrar la conexion
        serverSocket.close();
        clientSocket.close();
        
    }

    public static void main(String[] args)throws Exception{
        server servidor = new server();
        servidor.write("hola mundo");

    }

}
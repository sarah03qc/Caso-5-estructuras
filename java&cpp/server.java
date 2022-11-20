import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;
//#define DEFAULT_BUFLEN 512
//#define DEFAULT_PORT "6881" 

public class server
{
    public static void main(String[] args) throws Exception {
        ServerSocket serverSocket = null; 
        Socket clientSocket = null;
        serverSocket = new ServerSocket(8000); // 4447 is port number
        System.out.println("Esperando coneccion");
        clientSocket = serverSocket.accept(); // blocks and listen until a connection is made. 

        BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(clientSocket.getOutputStream())); 
        wr.write("My Messages!");
        wr.flush(); // flushes the stream

        String inputLine; 
        BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream())); 
        while((inputLine = in.readLine()) != null){
            System.out.println(inputLine);
        }

        serverSocket.close();
        clientSocket.close();
    }
}
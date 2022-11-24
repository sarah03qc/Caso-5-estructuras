

public class Receiver {

    public void getTopInfo() throws Exception {
        server servidor;
        String full = servidor.read();
        String[] all = full.split("[,], 0");
        Top10 top = new Top10();
        top.setProd1(all[0]);
        top.setProd2(all[1]);
        top.setProd3(all[2]);
        top.setProd4(all[3]);
        top.setProd5(all[4]);
        top.setProd6(all[5]);
        top.setProd7(all[6]);
        top.setProd8(all[7]);
        top.setProd9(all[8]);
        top.setProd10(all[9]);
        servidor = new server();
    }
}

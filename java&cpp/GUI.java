import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Font;
import java.awt.Color;
import javax.swing.JTextField;
import java.awt.SystemColor;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JCheckBox;
import javax.swing.JButton;


public class GUI {
	
	private JFrame frame;
	private final String FONT = "Sitka Display";
	private JLabel namelogo = new JLabel("GOBIZ");
	private JTextField Nickname = new JTextField();
	private JLabel nicknamelabel = new JLabel("Nickname:");
	private JTextField passwordInput1 = new JTextField();
	private JLabel password = new JLabel("Password:");
	private JLabel regist = new JLabel("Registration");
	private JCheckBox demandaCheck = new JCheckBox("Demanda");
	private JCheckBox offerCheck = new JCheckBox("Oferta");
	private JLabel select = new JLabel("Seleccione:");
	private JTextField demDescrip = new JTextField();
	private JLabel descrip = new JLabel("Enter your description:");
	private JButton signupboton = new JButton("sign up");
	private JTextField passwordInput2 = new JTextField();
	private JTextField offerDescrip = new JTextField();
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUI window = new GUI();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public GUI() {
		initialize();
	}

	private void initialize() {
		frame = new JFrame();
		//frame.getContentPane().setBackground(SystemColor.activeCaption);
		//frame.getContentPane().setForeground(SystemColor.desktop);
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		namelogo.setBounds(0, 11, 434, 35);
		namelogo.setFont(new Font(FONT, Font.PLAIN, 27));
		namelogo.setHorizontalAlignment(SwingConstants.CENTER);
		
		Nickname.setFont(new Font(FONT, Font.PLAIN, 13));
		Nickname.setBounds(27, 77, 94, 20);
		Nickname.setHorizontalAlignment(SwingConstants.CENTER);
		Nickname.setBackground(new Color(255, 255, 255));
		Nickname.setColumns(12);
		
		nicknamelabel.setFont(new Font(FONT, Font.PLAIN, 11));
		nicknamelabel.setBounds(50, 57, 49, 14);
		
		passwordInput1.setFont(new Font(FONT, Font.PLAIN, 13));
		passwordInput1.setHorizontalAlignment(SwingConstants.CENTER);
		passwordInput1.setColumns(12);
		passwordInput1.setBackground(Color.WHITE);
		passwordInput1.setBounds(306, 77, 94, 20);
		
		password.setFont(new Font(FONT, Font.PLAIN, 11));
		password.setBounds(326, 57, 56, 14);
		
		regist.setFont(new Font(FONT, Font.PLAIN, 11));
		regist.setBounds(197, 43, 63, 14);
		
		demandaCheck.setFont(new Font(FONT, Font.PLAIN, 14));
		demandaCheck.setBounds(27, 159, 97, 23);
		
		offerCheck.setFont(new Font(FONT, Font.PLAIN, 14));
		offerCheck.setBounds(27, 196, 97, 23);
		
		select.setFont(new Font(FONT, Font.PLAIN, 11));
		select.setBounds(50, 135, 49, 14);
		
		demDescrip.setFont(new Font(FONT, Font.PLAIN, 13));
		demDescrip.setHorizontalAlignment(SwingConstants.CENTER);
		demDescrip.setColumns(12);
		demDescrip.setBackground(Color.WHITE);
		demDescrip.setBounds(234, 159, 166, 23);
		
		descrip.setFont(new Font(FONT, Font.PLAIN, 11));
		descrip.setBounds(269, 141, 110, 14);
		
		signupboton.setFont(new Font(FONT, Font.PLAIN, 13));
		signupboton.setBounds(181, 227, 79, 23);
		
		passwordInput2.setHorizontalAlignment(SwingConstants.CENTER);
		passwordInput2.setFont(new Font(FONT, Font.PLAIN, 13));
		passwordInput2.setColumns(12);
		passwordInput2.setBackground(Color.WHITE);
		passwordInput2.setBounds(306, 108, 94, 20);
		
		offerDescrip.setHorizontalAlignment(SwingConstants.CENTER);
		offerDescrip.setFont(new Font(FONT, Font.PLAIN, 13));
		offerDescrip.setColumns(12);
		offerDescrip.setBackground(Color.WHITE);
		offerDescrip.setBounds(234, 196, 166, 23);

		signupboton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				String textoNickname = Nickname.getText();
				String textoPassword1 = passwordInput1.getText();
				String textoPassword2 = passwordInput2.getText();
				String textoDemDescrip = demDescrip.getText();
				String textoOfferDescrip = offerDescrip.getText();
				boolean valueDemandaCheck = demandaCheck.isSelected();
				boolean valueOfferCheck = offerCheck.isSelected();
<<<<<<< HEAD
				
=======

>>>>>>> cb7c5d8ea0305d2ec1e0c56e9e12341f8c7fde7d
				String fullinfo = textoNickname + "," + textoPassword1 + "," + textoPassword2 + "," + textoDemDescrip + "," + textoOfferDescrip;
				try {
					server servidor = new server();
					servidor.write(fullinfo);
					servidor.closeSockets();
				} catch(Exception ex) {
					ex.printStackTrace();
				}
			}
		});
		
		
		frame.getContentPane().setLayout(null);
		frame.getContentPane().add(namelogo);
		frame.getContentPane().add(Nickname);
		frame.getContentPane().add(nicknamelabel);
		frame.getContentPane().add(passwordInput1);
		frame.getContentPane().add(password);
		frame.getContentPane().add(regist);
		frame.getContentPane().add(demandaCheck);
		frame.getContentPane().add(offerCheck);
		frame.getContentPane().add(select);
		frame.getContentPane().add(demDescrip);
		frame.getContentPane().add(descrip);
		frame.getContentPane().add(signupboton);
		frame.getContentPane().add(passwordInput2);
		frame.getContentPane().add(offerDescrip);
	}
	
	public void sendRegistrationInfo() {
		
	}
}

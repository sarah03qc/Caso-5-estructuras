//package test;

import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import java.awt.Font;
import java.awt.Color;
import javax.swing.JTextField;
import java.awt.SystemColor;
import javax.swing.JCheckBox;
import javax.swing.JButton;

public class GUI {
	
	private JFrame frame;
	
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
		frame.getContentPane().setBackground(SystemColor.activeCaption);
		frame.getContentPane().setForeground(SystemColor.desktop);
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JLabel namelogo = new JLabel("GOBIZ");
		namelogo.setBounds(0, 11, 434, 35);
		namelogo.setFont(new Font("Sitka Display", Font.PLAIN, 27));
		namelogo.setHorizontalAlignment(SwingConstants.CENTER);
		
		JTextField Nickname = new JTextField();
		Nickname.setFont(new Font("Sitka Display", Font.PLAIN, 13));
		Nickname.setBounds(27, 77, 94, 20);
		Nickname.setHorizontalAlignment(SwingConstants.CENTER);
		Nickname.setBackground(new Color(255, 255, 255));
		Nickname.setColumns(12);
		
		JLabel nicknamelabel = new JLabel("Nickname:");
		nicknamelabel.setFont(new Font("Sitka Display", Font.PLAIN, 11));
		nicknamelabel.setBounds(50, 57, 49, 14);
		
		JTextField texto = new JTextField();
		texto.setFont(new Font("Sitka Display", Font.PLAIN, 13));
		texto.setHorizontalAlignment(SwingConstants.CENTER);
		texto.setColumns(12);
		texto.setBackground(Color.WHITE);
		texto.setBounds(306, 77, 94, 20);
		
		JLabel password = new JLabel("Password:");
		password.setFont(new Font("Sitka Display", Font.PLAIN, 11));
		password.setBounds(326, 57, 56, 14);
		
		JLabel regist = new JLabel("Registration");
		regist.setFont(new Font("Sitka Display", Font.PLAIN, 11));
		regist.setBounds(197, 43, 63, 14);
		
		JCheckBox demanda = new JCheckBox("Demanda");
		demanda.setFont(new Font("Sitka Display", Font.PLAIN, 14));
		demanda.setBounds(27, 159, 97, 23);
		
		JCheckBox offer = new JCheckBox("Oferta");
		offer.setFont(new Font("Sitka Display", Font.PLAIN, 14));
		offer.setBounds(27, 196, 97, 23);
		
		JLabel select = new JLabel("Seleccione:");
		select.setFont(new Font("Sitka Display", Font.PLAIN, 11));
		select.setBounds(50, 135, 49, 14);
		
		JTextField texto2 = new JTextField();
		texto2.setFont(new Font("Sitka Display", Font.PLAIN, 13));
		texto2.setHorizontalAlignment(SwingConstants.CENTER);
		texto2.setColumns(12);
		texto2.setBackground(Color.WHITE);
		texto2.setBounds(234, 159, 166, 23);
		
		JLabel descrip = new JLabel("Enter your description:");
		descrip.setFont(new Font("Sitka Display", Font.PLAIN, 11));
		descrip.setBounds(269, 141, 110, 14);
		
		JButton signupboton = new JButton("sign up");
		signupboton.setFont(new Font("Sitka Display", Font.PLAIN, 13));
		signupboton.setBounds(181, 227, 79, 23);
		
		JTextField texto3 = new JTextField();
		texto3.setHorizontalAlignment(SwingConstants.CENTER);
		texto3.setFont(new Font("Sitka Display", Font.PLAIN, 13));
		texto3.setColumns(12);
		texto3.setBackground(Color.WHITE);
		texto3.setBounds(306, 108, 94, 20);
		
		JTextField texto4 = new JTextField();
		texto4.setHorizontalAlignment(SwingConstants.CENTER);
		texto4.setFont(new Font("Sitka Display", Font.PLAIN, 13));
		texto4.setColumns(12);
		texto4.setBackground(Color.WHITE);
		texto4.setBounds(234, 196, 166, 23);
		
		
		frame.getContentPane().setLayout(null);
		frame.getContentPane().add(namelogo);
		frame.getContentPane().add(Nickname);
		frame.getContentPane().add(nicknamelabel);
		frame.getContentPane().add(texto);
		frame.getContentPane().add(password);
		frame.getContentPane().add(regist);
		frame.getContentPane().add(demanda);
		frame.getContentPane().add(offer);
		frame.getContentPane().add(select);
		frame.getContentPane().add(texto2);
		frame.getContentPane().add(descrip);
		frame.getContentPane().add(signupboton);
		frame.getContentPane().add(texto3);
		frame.getContentPane().add(texto4);
	}
}
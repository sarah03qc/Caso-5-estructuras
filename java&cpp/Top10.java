
import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Font;

public class Top10 {

	private JFrame frame;
	private final String FONT = "Sitka Display";
	private String prod1;
	private String prod2;
	private String prod3;
	private String prod4;
	private String prod5;
	private String prod6;
	private String prod7;
	private String prod8;
	private String prod9;
	private String prod10;

	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Top10 window = new Top10();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	public Top10() {
		initialize();
	}

	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel titulo = new JLabel("Top 10: productos y servicios codiciados");
		titulo.setFont(new Font(FONT, Font.PLAIN, 17));
		titulo.setBounds(67, 0, 333, 52);
		frame.getContentPane().add(titulo);
		
		JLabel p1 = new JLabel(prod1);
		p1.setFont(new Font(FONT, Font.PLAIN, 11));
		p1.setBounds(177, 43, 223, 14);
		frame.getContentPane().add(p1);
		
		JLabel p2 = new JLabel(prod2);
		p2.setFont(new Font(FONT, Font.PLAIN, 11));
		p2.setBounds(177, 63, 223, 14);
		frame.getContentPane().add(p2);
		
		JLabel p3 = new JLabel(prod3);
		p3.setFont(new Font(FONT, Font.PLAIN, 11));
		p3.setBounds(177, 88, 223, 14);
		frame.getContentPane().add(p3);
		
		JLabel p4 = new JLabel(prod4);
		p4.setFont(new Font(FONT, Font.PLAIN, 11));
		p4.setBounds(177, 113, 223, 14);
		frame.getContentPane().add(p4);
		
		JLabel p5 = new JLabel(prod5);
		p5.setFont(new Font(FONT, Font.PLAIN, 11));
		p5.setBounds(177, 138, 223, 14);
		frame.getContentPane().add(p5);
		
		JLabel p6 = new JLabel(prod6);
		p6.setFont(new Font(FONT, Font.PLAIN, 11));
		p6.setBounds(177, 163, 223, 14);
		frame.getContentPane().add(p6);
		
		JLabel p7 = new JLabel(prod7);
		p7.setFont(new Font(FONT, Font.PLAIN, 11));
		p7.setBounds(177, 180, 223, 14);
		frame.getContentPane().add(p7);
		
		JLabel p8 = new JLabel(prod8);
		p8.setFont(new Font(FONT, Font.PLAIN, 11));
		p8.setBounds(177, 199, 223, 14);
		frame.getContentPane().add(p8);
		
		JLabel p9 = new JLabel(prod9);
		p9.setFont(new Font(FONT, Font.PLAIN, 11));
		p9.setBounds(177, 217, 223, 14);
		frame.getContentPane().add(p9);
		
		JLabel p10 = new JLabel(prod10);
		p10.setFont(new Font(FONT, Font.PLAIN, 11));
		p10.setBounds(177, 236, 223, 14);
		frame.getContentPane().add(p10);
	}

	public void setProd1(String prod1) {
		this.prod1 = prod1;
	}

	public void setProd2(String prod2) {
		this.prod2 = prod2;
	}

	public void setProd3(String prod3) {
		this.prod3 = prod3;
	}

	public void setProd4(String prod4) {
		this.prod4 = prod4;
	}

	public void setProd5(String prod5) {
		this.prod5 = prod5;
	}

	public void setProd6(String prod6) {
		this.prod6 = prod6;
	}

	public void setProd7(String prod7) {
		this.prod7 = prod7;
	}

	public void setProd8(String prod8) {
		this.prod8 = prod8;
	}

	public void setProd9(String prod9) {
		this.prod9 = prod9;
	}

	public void setProd10(String prod10) {
		this.prod10 = prod10;
	}
}
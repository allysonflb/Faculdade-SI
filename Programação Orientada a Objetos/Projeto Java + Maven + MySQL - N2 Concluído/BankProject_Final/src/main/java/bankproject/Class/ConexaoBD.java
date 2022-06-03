package bankproject.Class;

import java.sql.Connection;
import java.sql.DriverManager;

/**
 *
 * @author Allyson Freire
 */
public class ConexaoBD {
    private static String host = "localhost";
    private static String porta = "3306";
    private static String db = "dbBankProject";
    private static String usuario = "rootapp";
    private static String senha = "1234";
    
    public static Connection conexaoDB(){
        try{
            Connection c = DriverManager.getConnection("jdbc:mysql://"+host+":"+porta+"/"+db,usuario,senha);
            return c;
        }catch (Exception e){
            e.printStackTrace();
            return null;
        }
    }
}

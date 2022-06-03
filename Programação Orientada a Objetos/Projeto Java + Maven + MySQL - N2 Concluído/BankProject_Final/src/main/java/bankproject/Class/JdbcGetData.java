package bankproject.Class;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 *
 * @author Allyson Freire
 */
public class JdbcGetData {
    
    public static void GetDT(Usuario User) throws SQLException{
        String sql = "select * from tb_usuario where login = ? and senha = ? ";
        try (Connection conexao = ConexaoBD.conexaoDB();
                PreparedStatement ps = conexao.prepareStatement(sql)){
            ps.setString(1, User.getLogin());
            ps.setString(2, User.getSenha());
            try (ResultSet rs = ps.executeQuery()){
               while (rs.next()){
                  User.setNome(rs.getString(2));
                  User.setSaldo(rs.getString(5));
                  User.setId(rs.getInt(1));
                  User.setLogin(rs.getString(3));
                  User.setSenha(rs.getString(4));
                  User.setPix(rs.getInt(6));
               } 
            }
        }
    }
    public static void GetDTPix(Usuario User) throws SQLException{
        String sql = "select * from tb_usuario where pix = ? ";
        try (Connection conexao = ConexaoBD.conexaoDB();
                PreparedStatement ps = conexao.prepareStatement(sql)){
            ps.setInt(1, User.getPix());
            try (ResultSet rs = ps.executeQuery()){
               while (rs.next()){
                  User.setNome(rs.getString(2));
                  User.setSaldo(rs.getString(5));
                  User.setId(rs.getInt(1));
                  User.setLogin(rs.getString(3));
                  User.setSenha(rs.getString(4));
                  User.setPix(rs.getInt(6));
               } 
            }
        }
    }
}
    

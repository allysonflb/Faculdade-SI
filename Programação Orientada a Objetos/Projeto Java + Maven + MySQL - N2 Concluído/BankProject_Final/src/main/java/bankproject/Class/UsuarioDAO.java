package bankproject.Class;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

/**
 *
 * @author Allyson Freire
 */
public class UsuarioDAO {
    
    public boolean isUser(Usuario usuario) throws Exception{
        String sql = "select * from tb_usuario where login = ? and senha = ? ";
        try (Connection conexao = ConexaoBD.conexaoDB();
            PreparedStatement ps = conexao.prepareStatement(sql)){
            ps.setString(1, usuario.getLogin());
            ps.setString(2, usuario.getSenha());
            try (ResultSet rs = ps.executeQuery()){
                return rs.next();
            }
        }
    }
    public void alterarUsuario(Usuario usuario) throws Exception{
        String sql = "UPDATE tb_usuario SET saldo = ? WHERE id = ? ";
        try (Connection conexao = ConexaoBD.conexaoDB();
            PreparedStatement ps = conexao.prepareStatement(sql)){
            ps.setString(1, usuario.getSaldo());
            ps.setInt(2, usuario.getId());
            ps.execute();            
        }
    }
    public boolean isUserPix(Usuario usuario) throws Exception{
        String sql = "select * from tb_usuario WHERE pix = ?";
        try (Connection conexao = ConexaoBD.conexaoDB();
            PreparedStatement ps = conexao.prepareStatement(sql)){
            ps.setInt(1, usuario.getPix());
            try (ResultSet rs = ps.executeQuery()){
            return rs.next();
            }
        }
    }
    
    public void pixUpdate(Usuario usuario) throws Exception{
        String sql = "UPDATE tb_usuario SET saldo = ? WHERE pix = ?";
        try (Connection conexao = ConexaoBD.conexaoDB();
            PreparedStatement ps = conexao.prepareStatement(sql)){
            ps.setString(1, usuario.getSaldo());
            ps.setInt(2, usuario.getPix());
            ps.execute();            
        }
    }
    public boolean inserirUsuario(Usuario usuario) throws Exception{
        String sql = "INSERT INTO tb_usuario (login, nome, senha, pix, saldo) VALUES (?, ?, ?, ?, ?)";
        try (Connection conexao = ConexaoBD.conexaoDB();
            PreparedStatement ps = conexao.prepareStatement(sql)){
            ps.setString(1, usuario.getLogin());
            ps.setString(2, usuario.getNome());
            ps.setString(3, usuario.getSenha());
            ps.setInt(4, usuario.getPix());
            ps.setString(5, usuario.getSaldo());
            ps.execute();
        }
        return false;
    }
}



/*
if (rs != null){
                    rs.getMetaData();
                    usuario.setNome(rs.getNString(3));
                    usuario.setSaldo(rs.getNString(4));
if (rs != null){
                    usuario.setNome(rs.getString(4));
                }
  */              


package bankproject.Class;

/**
 *
 * @author Allyson Freire
 */
public class Usuario {
    private int id;
    private String login;
    private String nome;
    private String senha;
    private String saldo;
    private int Pix;

    public Usuario() {
    }

    public Usuario(String login, String senha) {
        this.login = login;
        this.senha = senha;
    }    
    
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getLogin() {
        return login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSenha() {
        return senha;
    }

    public void setSenha(String senha) {
        this.senha = senha;
    }

    public String getSaldo() {
        return saldo;
    }

    public void setSaldo(String saldo) {
        this.saldo = saldo;
    }

    public int getPix() {
        return Pix;
    }

    public void setPix(int Pix) {
        this.Pix = Pix;
    }
}

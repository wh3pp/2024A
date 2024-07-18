<%@page import="java.io.IOException"%> 
<%@page import="java.sql.*"%> 

<%
class base_datos{
  private String host;
  private String usua;
  private String pass;
  private String bd;

  public Connection conexion;

  public base_datos(String host, String usua, String pass, String bd){
    this.host = host;
    this.usua = usua;
    this.pass = pass;
    this.bd = bd;
  }
  public boolean conectar() throws IOException, SQLException, ClassNotFoundException{
    try {
      Class.forName("org.mariadb.jdbc.Driver");
      this.conexion = DriverManager.getConnection("jdbc:mariadb://" + host + "/" + bd, usua, pass);
      if  (this.conexion == null){
        return false;
      }
    } catch (SQLException ex) {
      return false;
    }
    return true;
  }
  public ResultSet getClientes() throws IOException, SQLException{
    try {
      PreparedStatement ps = this.conexion.prepareStatement("SELECT * FROM clientes");
      ResultSet rs = ps.executeQuery();
      return rs;
    } catch (SQLException ex) {
      return null;
    }
  }
  public boolean insCliente(String dni, String nomb, String apelp, String apelm, String col) throws IOException, SQLException{
    try {
      PreparedStatement ps = this.conexion.prepareStatement("INSERT INTO clientes VALUES (" + dni + ", '" + nomb + "', '" + apelp + "', '" + apelm + "', '" + col + "')");
      ps.execute();
    } catch (SQLException ex) {
      return false;
    }
    return true;
  }
  public void cerrar() throws SQLException{
    this.conexion.close();
  }
}

%>

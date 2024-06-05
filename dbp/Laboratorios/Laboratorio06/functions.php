<?php
  function TablaPitagorica(){
    $fil = array();
    $col = array();
    for($i=0;$i<7;$i++){
      array_push($fil,rand(1,20));
      array_push($col,rand(1,20));
    }
    echo "<table class='tabla'>";
    echo "<thead>";
    echo "<tr>";
    echo "<td>X</td>";
    for($i=0; $i<7;$i++){
      echo "<td>".$fil[$i]."</td>";
    }
    echo "</tr>";
    echo "</thead>";
    for($i=0; $i<7; $i++){
      echo "<tr>";
      for($j=0; $j<8; $j++){
        if($j==0){
          echo "<td>".$col[$i]."</td>";
        }elseif($j==1){
          echo "<td class='azul'>".$fil[$j-1]*$col[$i]."</td>";
        }elseif($j==3){
          echo "<td class='naranja'>".$fil[$j-1]*$col[$i]."</td>";
        }elseif($j==5){
          echo "<td class='amarillo'>".$fil[$j-1]*$col[$i]."</td>";
        }elseif($j==7){
          echo "<td class='verde'>".$fil[$j-1]*$col[$i]."</td>";
        }else{
          echo "<td>".$fil[$j-1]*$col[$i]."</td>";
        }
      }
      echo "</tr>";
    }
    echo "</tr>";
    echo "</tbody>";
    echo "</table>";
  }
?>

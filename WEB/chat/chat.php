<?php
    session_start();
    $time = round(microtime(true) * 1000);
    $fn = "./chat";
    if (!file_exists($fn))
        $fp = fopen($fn, "x+");
    else
        $fp = fopen($fn, "r+");
    if (flock($fp, LOCK_EX))
    {
        $fc = fread($fp, filesize($fn));
        $tab = unserialize($fc);
        if (isset($_GET['msg']) && $_GET['msg'] != "")
            $tab[] = array ($time, $_SESSION["rank"], $_SESSION["username"], strip_tags($_GET['msg']));
        file_put_contents($fn, serialize($tab));
        fflush($fp);
        flock($fp, LOCK_UN);
        foreach ($tab as $line)
        {
            if ($line[0] >= $_GET["time"])
            {
                echo '<span id="span" class="r', $line[1], '"> ';
                echo '<img src="img/', $line[1], '.png" /> ';
                echo $line[2], ' : ';
                echo '</span><span id="span" class="r0">'; 
                echo $line[3];
                echo '</span><br />';
            }
        }
    }
?>
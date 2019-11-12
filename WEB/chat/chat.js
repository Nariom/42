var time = new Date().getTime();
function refresh(flag)
{
    var objText = document.getElementById('speak');
    var objDiv = document.getElementById('chat');
    xmlhttp=new XMLHttpRequest();
    xmlhttp.onreadystatechange=function()
    {
        if (xmlhttp.readyState==4 && xmlhttp.status==200)
        {
            objDiv.innerHTML = xmlhttp.responseText;
            objDiv.scrollTop = objDiv.scrollHeight;
        }
    }
    var target = "chat.php?time="+time;
    if (flag)
        target = target+"&msg="+objText.value;
    xmlhttp.open("GET",target,true);
    xmlhttp.send();
    if (flag)
        objText.value = "";
    objText.focus();
}
document.onload = setInterval(function(){refresh(false);},500);
document.getElementById('speak').onkeypress = function()
{
    if (event.keyCode == 13)
        refresh(true);
}
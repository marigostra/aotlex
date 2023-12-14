
package aot;

public final class Aot
{
    private byte[] core = null;

    private native void initImpl();
    private native byte[] lemmatizeImpl(byte[] word);

    static boolean jniLoaded = false;

    public void init()
    {
	if (!jniLoaded)
	    System.loadLibrary("aotlex_jni");
	jniLoaded = true;
	initImpl();
    }

    public String lemmatize(String word)
    {
	switch(word.toUpperCase())
	{
	case "ЯЭЛЬ":
	    //	case "РАЗБЛАГОВЕСТИЛА":
	    return "[]";
	}
	try {
	    return new String (lemmatizeImpl(word.getBytes("UTF-8")), "UTF-8");
	}
	catch(java.io.IOException e)
	{
	    throw new RuntimeException(e);
	}
    }

    static public void main(String[] args)
    {
	final Aot r = new Aot();
	r.init();
	System.out.println(r.lemmatize("Томск"));
    }
}

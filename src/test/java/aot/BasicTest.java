
package aot;

import org.junit.jupiter.api.*;
import static org.junit.jupiter.api.Assertions.*;

public class BasicTest
{
    @Test void loading()
    {
	final Aot aot = new Aot();
	aot.init();
	assertTrue(Aot.jniLoaded);
    }

        @Test void lemm()
    {
	final Aot aot = new Aot();
	aot.init();
	final String res = aot.lemmatize("стол");
	assertNotNull(res);
	assertEquals(1059, res.length());	
    }

    
}

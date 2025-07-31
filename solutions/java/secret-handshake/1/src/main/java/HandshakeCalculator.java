import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class HandshakeCalculator {

    List<Signal> calculateHandshake(int number) {
        Signal signals[] = {
            Signal.WINK,
            Signal.DOUBLE_BLINK,
            Signal.CLOSE_YOUR_EYES,
            Signal.JUMP
        };

        int reverse = 16;

        List<Signal> result = new ArrayList<Signal>();

        for (Signal s: signals) {
            int mask = 1 << s.ordinal();
            if ((mask & number) > 0) {
                result.add(s);
            }
        }

        if ((reverse & number) > 0) {
            Collections.reverse(result);
        }

        return result;
    }

}
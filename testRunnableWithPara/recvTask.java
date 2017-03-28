package testRunnableWithPara;

import java.util.concurrent.Callable;

/**
 * Created by mao on 2016/3/21.
 */
public class recvTask implements Callable {

    Integer radar;

    public recvTask(Integer r){
        radar = r;
    }

    @Override
    public Integer call(){
        System.out.println(radar);
        try {
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return radar;
    }

}